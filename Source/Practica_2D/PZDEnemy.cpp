// Fill out your copyright notice in the Description page of Project Settings.


#include "PZDEnemy.h"

#include "EnemyAnim.h"

void APZDEnemy::BeginPlay()
{
	Super::BeginPlay();

	EnemyAnimInstance = Cast<UCharacterAnimInstance>(GetAnimInstance());
}

void APZDEnemy::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void APZDEnemy::MoveEnemy()
{
	FVector fwd {GetActorForwardVector()};
	AddMovementInput(fwd);
}

void APZDEnemy::EnemyAttack()
{
	
}