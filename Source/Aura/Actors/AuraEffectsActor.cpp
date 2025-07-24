// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraEffectsActor.h"
#include "AbilitySystemInterface.h"
#include "Aura/AbilitySystem/AuraAttributeSet.h"
#include "Components/SphereComponent.h"

// Sets default values
AAuraEffectsActor::AAuraEffectsActor()
{
	PrimaryActorTick.bCanEverTick = false;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(mesh);
	sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	sphere->SetupAttachment(GetRootComponent());
}

void AAuraEffectsActor::OnOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor,
                                  UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep,
                                  const FHitResult& sweepResult)
{
	// TODO :: Use Gameplay Effects in the Future

	if (IAbilitySystemInterface* aciInterface = Cast<IAbilitySystemInterface>(otherActor))
	{
		const UAuraAttributeSet* auraAttributeSet = Cast<UAuraAttributeSet>(
			aciInterface->GetAbilitySystemComponent()->GetAttributeSet(UAuraAttributeSet::StaticClass()));
		UAuraAttributeSet* mutableAttributes = const_cast<UAuraAttributeSet*>(auraAttributeSet);
		mutableAttributes->Sethealth(auraAttributeSet->Gethealth() + 25.f);
		mutableAttributes->Setmana(auraAttributeSet->Getmana() - 25.f);
		Destroy();
	}
}

void AAuraEffectsActor::OnOverLapEnd(UPrimitiveComponent* overlappedComponent, AActor* otherActor,
                                     UPrimitiveComponent* otherComp, int32 otherBodyIndex)
{
}

void AAuraEffectsActor::BeginPlay()
{
	Super::BeginPlay();

	sphere->OnComponentBeginOverlap.AddDynamic(this, &AAuraEffectsActor::OnOverlap);
	sphere->OnComponentEndOverlap.AddDynamic(this, &AAuraEffectsActor::OnOverLapEnd);
}