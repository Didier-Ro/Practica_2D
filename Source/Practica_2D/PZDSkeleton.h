// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "SkeletonAnimInstance.h"
#include "PZDSkeleton.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICA_2D_API APZDSkeleton : public APaperZDCharacter
{
	GENERATED_BODY()
	
private:
	float currenTime{};
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attack")
	int32 Damage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Patrol")
	float TimeSleep;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Patrol")
	float TimePatrol;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Patrol")
	FVector CurrentDirection{};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attack")
	bool CanAttack{};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Patrol")
	bool IsPatrolling{};

	UFUNCTION(BlueprintCallable, Category = "Patrol")
	void Patrolling();

	UFUNCTION(BlueprintCallable, Category = "Patrol")
	void Die();

	UFUNCTION(BlueprintCallable, Category = "Patrol")
	void StartAttack();

	UFUNCTION(BlueprintCallable, Category = "Patrol")
	void GoSleep();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

private:
	UPaperFlipbookComponent * Sprite;
	USkeletonAnimInstance* SkeletonAnimInstance;
};
