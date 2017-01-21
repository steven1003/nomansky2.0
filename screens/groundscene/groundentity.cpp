#include "groundentity.hpp"

bool GroundEntity::intersects(GroundEntity &e) {
    return boundingBox.intersects(e.boundingBox);
}
