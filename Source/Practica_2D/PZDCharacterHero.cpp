// Fill out your copyright notice in the Description page of Project Settings.


#include "PZDCharacterHero.h"
#include  "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "PaperFlipbookComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

void APZDCharacterHero::BeginPlay()
{
	Super::BeginPlay();
	
	CharacterAnimInstance = Cast<UCharacterAnimInstance>(GetAnimInstance());
	
	if (APlayerController* PlayerController{ Cast<APlayerController>(GetController())})
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem{ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer())})
		{
			Subsystem->AddMappingContext(MappingContext, 0);
		}
	}
}

void APZDCharacterHero::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	IsNotTouchingGround = GetCharacterMovement()->IsFalling();
	CharacterAnimInstance->IsNotTouchingGround = IsNotTouchingGround;
	IsFalling = GetVelocity().Z < 0.f;
	CharacterAnimInstance->IsFalling = IsFalling;

	if (IsJumping && !IsNotTouchingGround)
	{
		IsJumping = false;
		CharacterAnimInstance->IsJumping = IsJumping;
	}
}

void APZDCharacterHero::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent{CastChecked<UEnhancedInputComponent>(PlayerInputComponent)})
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APZDCharacterHero::MoveRight);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this, &APZDCharacterHero::CancelMoveRight);
		EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Triggered, this, &APZDCharacterHero::StartAttack);
		//EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Completed, this, &APZDCharacterHero::FinishAttack);
		EnhancedInputComponent->BindAction(JumpsAction, ETriggerEvent::Triggered, this, &APZDCharacterHero::StartJump);
	}
}

void APZDCharacterHero::MoveRight(const FInputActionValue& value)
{
	float moveValue {value.Get<float>()};
	CurrentDirection = abs(moveValue) > 0.2f ? moveValue : 0.0f;
	FVector fwd {GetActorForwardVector()};
	 
	AddMovementInput(fwd, CurrentDirection);

	GetSprite()->SetRelativeScale3D(FVector(CurrentDirection > 0.f ? 1.f : CurrentDirection < 0.f ? -1.f : GetSprite()->GetRelativeScale3D().X, 1.f, 1.f));
	CharacterAnimInstance->CurrentDirection = abs( CurrentDirection);
	CharacterAnimInstance->IsAttacking = false;
}

void APZDCharacterHero::StartJump(const FInputActionValue& value)
{
	if (!IsJumping)
	{
		Jump();
	}
	IsJumping = value.Get<bool>() && !IsNotTouchingGround;
	CharacterAnimInstance->IsJumping = IsJumping;
}

void APZDCharacterHero::StartAttack(const FInputActionValue& value)
{
	if (!IsAttacking)
	{
		CharacterAnimInstance->IsAttacking = value.Get<bool>();
	}
}

void APZDCharacterHero::CancelMoveRight(const FInputActionValue& value)
{
	CurrentDirection = 0.f;
	CharacterAnimInstance->CurrentDirection = CurrentDirection;
}
