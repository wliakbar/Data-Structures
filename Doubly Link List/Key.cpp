
#include "Key.h"
#include "Value.h"

Key::Key(int x, Value* y, Value* z) {
	keys=x;
	headptr=y;
	prevptr=z;
}
