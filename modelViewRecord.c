#include <stdlib.h>

#include "modelViewRecord.h"

ViewRecord* viewRecord_create(int pointCount) {
    ViewRecord* result = malloc(sizeof (*result));
    int i, totalCount;
    double* pos;

    if (result == NULL) {
        // ERR
        return NULL;
    }

    totalCount = 3 * pointCount;
    result->points = calloc(totalCount, sizeof (*(result->points)));
    if (result->points == NULL) {
        // ERR
        free(result);
        return NULL;
    }

    result->pointCount = pointCount;
    for (i = 0; i < 3; ++i) {
        result->cam[i] = 0;
    }

    pos = result->points;
    for (i = 0; i < totalCount; ++i, ++pos) {
        *pos = 0.0;
    }

    return result;
}

ViewRecord* viewRecord_create3f(int pointCount, float x, float y, float z) {
    ViewRecord* result = viewRecord_create(pointCount);
    if (result != NULL) {
        result->cam[0] = x;
        result->cam[1] = y;
        result->cam[2] = z;
    }

    return result;
}

ViewRecord* viewRecord_create3d(int pointCount, double x, double y, double z) {
    ViewRecord* result = viewRecord_create(pointCount);
    if (result != NULL) {
        result->cam[0] = x;
        result->cam[1] = y;
        result->cam[2] = z;
    }

    return result;
}

void viewRecord_setTestTargetf(ViewRecord* record, int index, float x, float y, float z) {
    viewRecord_setTestTargetd(record, index, (double) x, (double) y, (double) z);
}

void viewRecord_setTestTargetd(ViewRecord* record, int index, double x, double y, double z) {
    viewRecord_setTestViewDirectiond(record, index,
            x - record->cam[0],
            y - record->cam[1],
            z - record->cam[2]);
}

void viewRecord_setTestViewDirectionf(ViewRecord* record, int index, float x, float y, float z) {
    viewRecord_setTestViewDirectiond(record, index, (double) x, (double) y, (double) z);
}

void viewRecord_setTestViewDirectiond(ViewRecord* record, int index, double x, double y, double z) {
    double* pos = record->points + 3 * index;

    pos[0] = x;
    pos[1] = y;
    pos[2] = z;

}
