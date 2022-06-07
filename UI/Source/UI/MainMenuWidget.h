// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class UI_API UMainMenuWidget : public UUserWidget
{
public:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(meta = (BindWidgetOptional))
	UButton *ShowTankStatusWidgetButton;
	UPROPERTY(meta = (BindWidgetOptional))
	UButton *ShowEnemyStatusWidgetButton;

protected:
	UFUNCTION()
	void OnShowTankStatusWidgetButtonClicked();
		
	GENERATED_BODY()
	
};
