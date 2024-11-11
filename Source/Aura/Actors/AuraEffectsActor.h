// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AuraEffectsActor.generated.h"

class USphereComponent;

UCLASS()
class AURA_API AAuraEffectsActor : public AActor
{
	GENERATED_BODY()

public:
	AAuraEffectsActor();

	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComp,
	                       int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult);
	UFUNCTION()
	virtual void OnOverLapEnd(UPrimitiveComponent* overlappedComponent, AActor* otherActor,
	                          UPrimitiveComponent* otherComp, int32 otherBodyIndex);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> sphere;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> mesh;
};
