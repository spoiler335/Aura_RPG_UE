// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraEnemy.h"

#include "Aura/Aura.h"
#include "Aura/AbilitySystem/AuraAbilitySystemComponent.h"
#include "Aura/AbilitySystem/AuraAttributeSet.h"

AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	abilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	abilitySystemComponent->SetIsReplicated(true);
	abilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	attributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
}

void AAuraEnemy::HighLightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_RED_DEPTH);
	weapon->SetRenderCustomDepth(true);
	weapon->SetCustomDepthStencilValue(CUSTOM_RED_DEPTH);
}

void AAuraEnemy::UnHighLightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	weapon->SetRenderCustomDepth(false);
}

void AAuraEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	abilitySystemComponent->InitAbilityActorInfo(this, this);
}
