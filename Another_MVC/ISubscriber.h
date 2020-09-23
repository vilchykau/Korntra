#pragma once

class ISubscriber
{
public:
	virtual void handleEvent() = 0;
};

