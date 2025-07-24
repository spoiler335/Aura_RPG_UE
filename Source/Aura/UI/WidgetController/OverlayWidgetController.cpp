// Fill out your copyright notice in the Description page of Project Settings.


#include "OverlayWidgetController.h"

#include "Aura/AbilitySystem/AuraAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UAuraAttributeSet* auraAttributeSet = CastChecked<UAuraAttributeSet>(attributeSet);
	onHealthChange.Broadcast(auraAttributeSet->Gethealth());
	onMaxHealthChange.Broadcast(auraAttributeSet->GetmaxHealth());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UAuraAttributeSet* auraAttributeSet = CastChecked<UAuraAttributeSet>(attributeSet);

	abilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		auraAttributeSet->GethealthAttribute()).AddUObject(
			this, &UOverlayWidgetController::HealthChanged);

	abilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		auraAttributeSet->GetmaxHealthAttribute()).AddUObject(
			this, &UOverlayWidgetController::MaxHealthChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& data) const
{
	onHealthChange.Broadcast(data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& data) const
{
	onMaxHealthChange.Broadcast(data.NewValue);
}
