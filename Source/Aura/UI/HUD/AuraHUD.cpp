// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraHUD.h"
#include "Blueprint/UserWidget.h"
#include "Aura/UI/Widget/AuraUserWidget.h"
#include "Aura/UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& wcParams)
{
	if (!overlayWidgetController)
	{
		overlayWidgetController = NewObject<UOverlayWidgetController>(this,overlayWidgetControllerClass);
		overlayWidgetController->SetWidgetControllerParams(wcParams);
	}

	return overlayWidgetController;
}

void AAuraHUD::InitOverlay(APlayerController* pc, APlayerState* ps, UAbilitySystemComponent* acs, UAttributeSet* as)
{
	checkf(overlayWidgetClass,TEXT("overlayWidgetClass is null"));
	checkf(overlayWidgetControllerClass,TEXT("overlayWidgetControllerClass is null"));
	
	UUserWidget* widget = CreateWidget<UAuraUserWidget>(GetWorld(), overlayWidgetClass);
	overlayWidget=Cast<	UAuraUserWidget>(widget);
	const FWidgetControllerParams wcParams(pc,ps,acs,as);

	UOverlayWidgetController* lOverlayWC = GetOverlayWidgetController(wcParams);
	checkf(lOverlayWC,TEXT("overlayWidgetController is null"));
	overlayWidget->SetWidgetController(lOverlayWC);
	
	widget->AddToViewport();
}
