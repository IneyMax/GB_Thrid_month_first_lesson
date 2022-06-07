// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SSlateRadioButtons.h"
#include "RadioButtons.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRadioButtonChangedEvent, ERadioChoice, NewRadioChoise);

UCLASS()
class UI_API URadioButtons : public UWidget
{
	GENERATED_BODY()

public:
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	
protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;
	void HandleRadioButtonStateChanged(ERadioChoice NewRadioChoise);

public:
	UPROPERTY(BlueprintAssignable)
	FOnRadioButtonChangedEvent OnRadioButtonChanged;
protected:
	TSharedPtr<SSlateRadioButtons> MyRadioButton;
};

