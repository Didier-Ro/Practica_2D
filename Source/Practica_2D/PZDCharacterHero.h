// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterAnimInstance.h"
#include "PaperZDCharacter.h"
#include "PZDCharacterHero.generated.h"

/**
 * 
 */
class UInputAction;
class UInputMappingContext;

UCLASS()
class PRACTICA_2D_API APZDCharacterHero : public APaperZDCharacter
{
	GENERATED_BODY()

public:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Character Movement")
	void MoveRight(const FInputActionValue& value);

	UFUNCTION(BlueprintCallable, Category = "CharacterAction")
	void CancelMoveRight(const FInputActionValue& value);
	
	UFUNCTION(BlueprintCallable, Category = "Character Movement")
	void StartJump(const FInputActionValue& value);

	UFUNCTION(BlueprintCallable, Category = "Character Action")
	void StartAttack(const FInputActionValue& value);

	UFUNCTION(BlueprintCallable, Category = "Character Health")
	void MakeDamage(const float damage);

	UFUNCTION(BlueprintCallable, Category = "Character Health")
	void RestoreHealth(const float health);
	
protected:
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health", meta=(UIMin = "0.0", UIMax = "1.0"))
	float currentHealth;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float CurrentDirection{};

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool IsJumping;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool IsFalling;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool IsNotTouchingGround;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool IsAttacking;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* AttackAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* JumpsAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputMappingContext* MappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category ="AnimInstance")
	UCharacterAnimInstance* CharacterAnimInstance;
};
