// Fill out your copyright notice in the Description page of Project Settings.


#include "OverlayWidgetController.h"

#include "Aura/AbilitySystem/AuraAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UAuraAttributeSet* auraAttributeSet = CastChecked<UAuraAttributeSet>(attributeSet);
	onHealthChange.Broadcast(auraAttributeSet->Gethealth());
	onMaxHealthChange.Broadcast(auraAttributeSet->GetmaxHealth());
}
