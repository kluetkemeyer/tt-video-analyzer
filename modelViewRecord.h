/* 
 * File:   modelViewRecord.h
 * Author: Kilian Lütkemeyer <kilian@luetkemeyer.com>
 *
 * Created on 23. Februar 2015, 12:40
 */

#ifndef MODELVIEWRECORD_H
#define	MODELVIEWRECORD_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    typedef struct {
        double cam[3];
        int pointCount;
        double *points;
    } ViewRecord;

    ViewRecord* viewRecord_create(int pointCount);
    ViewRecord* viewRecord_create3f(int pointCount, float x, float y, float z);
    ViewRecord* viewRecord_create3d(int pointCount, double x, double y, double z);
    
    void viewRecord_setTestTargetf(ViewRecord *record, int index, float x, float y, float z);
    void viewRecord_setTestTargetd(ViewRecord *record, int index, double x, double y, double z);
    void viewRecord_setTestViewDirectionf(ViewRecord *record, int index, float x, float y, float z);
    void viewRecord_setTestViewDirectiond(ViewRecord *record, int index, double x, double y, double z);


#ifdef	__cplusplus
}
#endif

#endif	/* MODELVIEWRECORD_H */

