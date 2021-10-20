#include <apriltag/apriltag.h>
#include <apriltag/tagStandard41h12.h>

int main()
{
    image_u8_t *im = image_u8_create_from_pnm("../test.pnm");
    if (im == NULL) {
        printf("Can not load img!\n");
        return 1;
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
        printf("%fx %fy\n", det->c[0], det->c[1]);
    }
    // Cleanup.
    tagStandard41h12_destroy(tf);
    apriltag_detector_destroy(td);

    return 0;
}