// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerBase.generated.h"

/**
 * 
 */

class ACharacterBase;

UCLASS()
class ASTEROID_API APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

public:
	void MoveForward(float fValue);
	void MoveRight(float fValue);
	void Turn(float fValue);
	void LookUp(float fValue);

protected:
	ACharacterBase* CachedCharacter;

};
