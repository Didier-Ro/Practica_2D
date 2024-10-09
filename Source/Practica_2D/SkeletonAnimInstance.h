// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDAnimInstance.h"
#include "SkeletonAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICA_2D_API USkeletonAnimInstance : public UPaperZDAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentDirection{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsAttacking;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsPatrolling;

private:
};
