// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AuraEffectsActor.generated.h"

class UGameplayEffect;

UCLASS()
class AURA_API AAuraEffectsActor : public AActor
{
	GENERATED_BODY()

public:
	AAuraEffectsActor();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* targetActor, TSubclassOf<UGameplayEffect> gameplayEffectClass);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly ,Category="Applied Effects")
	TSubclassOf<UGameplayEffect> instantGamePlayEffectClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly ,Category="Applied Effects")
	TSubclassOf<UGameplayEffect> durationGamePlayEffectClass;
};
