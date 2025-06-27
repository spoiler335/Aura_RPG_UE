// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraHUD.h"
#include "Blueprint/UserWidget.h"
#include "Aura/UI/Widget/AuraUserWidget.h"

void AAuraHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* widget = CreateWidget<UAuraUserWidget>(GetWorld(), overlayWidgetClass);
	if (widget)
		widget->AddToViewport();
}
