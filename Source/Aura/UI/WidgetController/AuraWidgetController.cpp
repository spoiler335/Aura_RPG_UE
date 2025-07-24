// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraWidgetController.h"


void UAuraWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WidgetControllerParams)
{
	playerController = WidgetControllerParams.playerController;
	playerState = WidgetControllerParams.playerState;
	abilitySystemComponent = WidgetControllerParams.abilitySystemComponent;
	attributeSet = WidgetControllerParams.attributeSet;
}

void UAuraWidgetController::BroadcastInitialValues()
{
	
}

void UAuraWidgetController::BindCallbacksToDependencies()
{
}
