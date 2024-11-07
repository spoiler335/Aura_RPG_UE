// Fill out your copyright notice in the Description page of Project Settings.

#include "AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"


AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(auraContext);

	UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		GetLocalPlayer());

	check(subsystem);

	subsystem->AddMappingContext(auraContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI inputModeData;
	inputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	inputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(inputModeData);
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* enchancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	enchancedInputComponent->BindAction(moveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const FInputActionValue& inputActionValue)
{
	const FVector2d inputAxisVector = inputActionValue.Get<FVector2d>();
	const FRotator rotation = GetControlRotation();
	const FRotator yawRotation(0, rotation.Yaw, 0);

	const FVector forwardDirection = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::X);
	const FVector rightDirection = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* controllerPawn = GetPawn<APawn>())
	{
		controllerPawn->AddMovementInput(forwardDirection, inputAxisVector.Y);
		controllerPawn->AddMovementInput(rightDirection, inputAxisVector.X);
	}
}

void AAuraPlayerController::CursorTrace()
{
	FHitResult cursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, cursorHit);
	if (!cursorHit.bBlockingHit) return;

	lastActor = thisActor;
	thisActor = cursorHit.GetActor();

	if (!lastActor)
	{
		if (thisActor)
		{
			thisActor->HighLightActor();
		}
	}
	else
	{
		if (!thisActor)
		{
			lastActor->UnHighLightActor();
		}
		else
		{
			if (lastActor != thisActor)
			{
				lastActor->UnHighLightActor();
				thisActor->HighLightActor();
			}
		}
	}
}
