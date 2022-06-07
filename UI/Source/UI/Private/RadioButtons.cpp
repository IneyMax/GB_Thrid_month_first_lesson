#include "RadioButtons.h"

void URadioButtons::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	MyRadioButton.Reset();
}

TSharedRef<SWidget> URadioButtons::RebuildWidget()
{
	MyRadioButton = SNew(SSlateRadioButtons)
	.OnRadioButtonChanged(BIND_UOBJECT_DELEGATE(FOnRadioButtonChanged, HandleRadioButtonStateChanged));

	return  MyRadioButton.ToSharedRef();
}

void URadioButtons::HandleRadioButtonStateChanged(ERadioChoice NewRadioChoise)
{
	if(OnRadioButtonChanged.IsBound())
	{
		OnRadioButtonChanged.Broadcast(NewRadioChoise);
	}
}

