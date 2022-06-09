// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SSlateRadioButtons.h"
#include "RadioButtons.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRadioButtonChangedEvent, int32, NewRadioChoise);

UCLASS()
class UI_API URadioButtons : public UWidget
{
	GENERATED_BODY()

public:
	
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	
protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;
	
	void HandleRadioButtonStateChanged (int32 NewRadioChoise);

public:
	UPROPERTY(BlueprintAssignable)
	FOnRadioButtonChangedEvent OnRadioButtonChanged;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
	int32 NumberOfOptions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
	int32 DefaultOptions;
	
protected:
	TSharedPtr<SSlateRadioButtons> MyRadioButton;
};

