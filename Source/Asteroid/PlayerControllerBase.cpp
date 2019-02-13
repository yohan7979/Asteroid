// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerControllerBase.h"
#include "CharacterBase.h"
#include "Components/InputComponent.h"
#include "Kismet/KismetMathLibrary.h"

void APlayerControllerBase::BeginPlay()
{
	CachedCharacter = Cast<ACharacterBase>(GetCharacter());
}

void APlayerControllerBase::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &APlayerControllerBase::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &APlayerControllerBase::MoveRight);
	InputComponent->BindAxis("Turn", this, &APlayerControllerBase::Turn);
	InputComponent->BindAxis("LookUp", this, &APlayerControllerBase::LookUp);
}

void APlayerControllerBase::MoveForward(float fValue)
{
	float roll, pitch, yaw;
	UKismetMathLibrary::BreakRotator(GetControlRotation(), roll, pitch, yaw);
	FRotator rot = UKismetMathLibrary::MakeRotator(0.f, 0.f, yaw);
	FVector forward = UKismetMathLibrary::GetForwardVector(rot);

	if (CachedCharacter)
		CachedCharacter->MoveCharacter(forward, fValue);
}

void APlayerControllerBase::MoveRight(float fValue)
{
	float roll, pitch, yaw;
	UKismetMathLibrary::BreakRotator(GetControlRotation(), roll, pitch, yaw);
	FRotator rot = UKismetMathLibrary::MakeRotator(0.f, 0.f, yaw);
	FVector right = UKismetMathLibrary::GetRightVector(rot);

	if (CachedCharacter)
		CachedCharacter->MoveCharacter(right, fValue);
}

void APlayerControllerBase::Turn(float fValue)
{
	AddYawInput(fValue);
}

void APlayerControllerBase::LookUp(float fValue)
{
	AddPitchInput(fValue);
}
