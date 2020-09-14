#include "ContainerViewerColors.h"

ContainerViewerColors::ContainerViewerColors() {
	c = { RGB(51,255,127),
		RGB(51, 173,255),
		RGB(95, 51, 255),
		RGB(255, 51, 227),
		RGB(255, 51, 79),
		RGB(255, 153, 51),
		RGB(255, 236, 51),
		RGB(80, 230, 215),
		RGB(146, 80, 230) };
}

int ContainerViewerColors::color() {
	return c[counter++ % c.size()];
}