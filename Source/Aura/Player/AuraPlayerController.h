// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInput/Public/InputMappingContext.h"
#include "InputActionValue.h"
#include "InputAction.h"
#include "Aura/Interaction/EnemyInterface.h"
#include "AuraPlayerController.generated.h"

/**
 *
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AAuraPlayerController();
	virtual void PlayerTick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> auraContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> moveAction;

	void Move(const FInputActionValue& inputActionValue);

	void CursorTrace();

	TScriptInterface<IEnemyInterface> lastActor;
	TScriptInterface<IEnemyInterface> thisActor;
};
