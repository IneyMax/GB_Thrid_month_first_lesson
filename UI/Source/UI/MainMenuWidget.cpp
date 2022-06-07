// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"

void UMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if (ShowTankStatusWidgetButton)
	{
		ShowTankStatusWidgetButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnShowTankStatusWidgetButtonClicked);
	}
}

void UMainMenuWidget::OnShowTankStatusWidgetButtonClicked()
{
	
}
