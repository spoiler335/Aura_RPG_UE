// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"

class UAuraUserWidget;
class UOverlayWidgetController;
struct  FWidgetControllerParams;

/**
 * 
 */
UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()

public:

	UPROPERTY()
	TObjectPtr<UAuraUserWidget> overlayWidget;

	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& wcParams);

	void InitOverlay(APlayerController* pc, APlayerState* ps,UAbilitySystemComponent* acs, UAttributeSet* as);

	
private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> overlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> overlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> overlayWidgetControllerClass;
};
