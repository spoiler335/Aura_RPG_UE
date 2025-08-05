// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraEffectsActor.h"
#include "AbilitySystemInterface.h"
#include "Aura/AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystemBlueprintLibrary.h"

// Sets default values
AAuraEffectsActor::AAuraEffectsActor()
{
	PrimaryActorTick.bCanEverTick = false;
	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}

void AAuraEffectsActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraEffectsActor::ApplyEffectToTarget(AActor* targetActor, TSubclassOf<UGameplayEffect> gameplayEffectClass)
{
	UAbilitySystemComponent* targetAsc = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(targetActor);
	if (!targetAsc) return;

	check(gameplayEffectClass); 

	FGameplayEffectContextHandle effectContextHandle = targetAsc->MakeEffectContext();
	effectContextHandle.AddSourceObject(this);
	FGameplayEffectSpecHandle effectSpecHandle = targetAsc->MakeOutgoingSpec(gameplayEffectClass,1.f,effectContextHandle);
	targetAsc->ApplyGameplayEffectSpecToSelf(*effectSpecHandle.Data.Get());
}
