#include <apriltag/apriltag.h>
#include <apriltag/tagStandard41h12.h>

int main()
{
    image_u8_t *im = image_u8_create_from_pnm("/home/dh/Programming/C/aprilfools/test.png");
    void * null = NULL;
    if (im == NULL) {
        printf("Can't load img!");
    }
    apriltag_detector_t *td = apriltag_detector_create();
    apriltag_family_t *tf = tagStandard41h12_create();
    apriltag_detector_add_family(td, tf);
    zarray_t *detections = apriltag_detector_detect(td, im);

    for (int i = 0; i < zarray_size(detections); i++)
    {
        apriltag_detection_t *det;
        zarray_get(detections, i, &det);

        // Do stuff with detections here.
    }
    // Cleanup.
    tagStandard41h12_destroy(tf);
    apriltag_detector_destroy(td);

    return 0;
}