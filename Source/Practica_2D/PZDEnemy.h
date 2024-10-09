// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterAnimInstance.h"
#include "PaperZDCharacter.h"
#include "PZDEnemy.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICA_2D_API APZDEnemy : public APaperZDCharacter
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Enemy Movement")
	void MoveEnemy();

	UFUNCTION(BlueprintCallable, Category = "Enemy Movement")
	void EnemyAttack();

protected:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category ="AnimInstance")
	UCharacterAnimInstance* EnemyAnimInstance;
};
