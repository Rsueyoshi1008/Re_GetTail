// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InputMappingContext.h" // 追加
#include "InputAction.h" // 追加
#include "InputActionValue.h" // 追加
#include "CPPActorBase.generated.h"

UCLASS()
class GETTAIL_API ACPPActorBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPPActorBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Called for Action input */
	void EventAction(const FInputActionValue& Value);

	/** Called for Axis input */
	void EventAxis(const FInputActionValue& Value);

	/** MappingContext */
	UPROPERTY(EditAnywhere, Category = Input)
	class UInputMappingContext* DefaultMappingContext;

	/** Action Input */
	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* ActionInput;

	/** Axis Input */
	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* AxisInput;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	// Input設定
	void SetupInput();

	// Input Event(Action) イベントハンドラー関数
	void PressedAction();
	void ReleasedAction();

	// Input Event(Axis) イベントハンドラー関数
	void PressedAxis(const FInputActionValue& Value);

	// Press状態を管理
	bool IsPressed = false;

	// 移動に関する変数
	float TotalElapsedTime = 0.0f;
	bool bMovingForward = true;

};
