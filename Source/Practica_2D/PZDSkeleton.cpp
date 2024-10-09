// Fill out your copyright notice in the Description page of Project Settings.


#include "PZDSkeleton.h"
#include "PaperFlipbookComponent.h"

void APZDSkeleton::BeginPlay()
{
	Super::BeginPlay();

	SkeletonAnimInstance = Cast<USkeletonAnimInstance>(GetAnimInstance());
	
	CurrentDirection = FVector{GetActorForwardVector()};

	Sprite = GetSprite();
}

void APZDSkeleton::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	currenTime += DeltaSeconds;
	
	if (currenTime > TimePatrol && IsPatrolling)
	{
		CurrentDirection = CurrentDirection == FVector::ForwardVector?  FVector::BackwardVector : FVector::ForwardVector;
		currenTime = 0;
		IsPatrolling = false;
		SkeletonAnimInstance->IsPatrolling = IsPatrolling;
		Sprite->SetRelativeScale3D(FVector(CurrentDirection.X > 0.f ? 1.f : CurrentDirection.X < 0.f ? -1.f : GetSprite()->GetRelativeScale3D().X, 1.f, 1.f));
		SkeletonAnimInstance->CurrentDirection = abs(CurrentDirection.X);
	}
	else if (!IsPatrolling && currenTime > TimeSleep)
	{
		GoSleep();
		currenTime = 0;
		IsPatrolling = true;
		SkeletonAnimInstance->IsPatrolling = IsPatrolling;
	}
	Patrolling();
}

void APZDSkeleton::Patrolling()
{
	if (IsPatrolling)
	{
		AddMovementInput(CurrentDirection);
	}
}

void APZDSkeleton::Die()
{
}

void APZDSkeleton::StartAttack()
{
}


void APZDSkeleton::GoSleep()
{
	
}

