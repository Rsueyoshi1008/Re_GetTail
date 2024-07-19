// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UTimeTextUI.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Blueprint/UserWidget.h"

#include "InGame_UI.generated.h"


UCLASS()
class GETTAIL_API AInGame_UI : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInGame_UI();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// ウィジェットクラスの参照を保持する変数
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UTimeTextUI> WidgetClass;

	// ウィジェットインスタンスを保持する変数
	UTimeTextUI* MyWidget;

};
