// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDAnimInstance.h"
#include "CharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class PRACTICA_2D_API UCharacterAnimInstance : public UPaperZDAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentDirection{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsJumping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsFalling;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsAttacking;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsNotTouchingGround;
};
