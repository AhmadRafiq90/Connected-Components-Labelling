# Dermoscopy Lesion Detection

This project aims to detect lesions in dermoscopy images using image processing techniques, specifically connected component labeling and K-means clustering. The project includes four tasks: connected component labeling for lesion region detection, K-means clustering for lesion region segmentation, evaluation using ground truth images, and run-length coding for image compression.

## Task 1: Connected Component Labeling

Connected component labeling is a technique used to group pixels in an image based on their connectivity and intensity values. In this task, the algorithm implements connected component labeling to detect the lesion region in dermoscopy images. The provided images in the "Segmented Outputs" folder have already narrowed down the lesion region, represented as 1. If multiple independent components are detected, the algorithm considers the largest component as the lesion, which occupies the maximum number of pixels.

## Task 2: K-means Clustering

K-means clustering is an unsupervised algorithm used for image segmentation. In this task, the algorithm applies K-means clustering to the original colored dermoscopy images to detect the lesion region. The algorithm partitions the image into two clusters based on pixel values: one centroid for the lesion region and one for the non-lesion region. The lesion region is represented as 1, while the rest of the image is represented as 0.

## Task 3: Evaluation using Ground Truth Images

To evaluate the performance of the lesion detection algorithms, ground truth images of correctly identified lesions are provided. The algorithm compares the detected lesion images with the ground truth images and calculates the DICE coefficient, a performance parameter that measures the overlap between the detected lesions and the ground truth lesions. The DICE coefficient considers true positives (pixels correctly identified as lesions) and false positives (pixels wrongly detected as lesions).

## Task 4: Run Length Coding (RLC) for Image Compression

Run Length Coding (RLC) is an image compression technique that exploits redundancy in pixel value information among neighboring pixels. In this task, the algorithm implements RLC for the segmented output images. The RLC algorithm proceeds row-wise and stores the indices of contiguous segments of the required pixel value. The encoded RLC images are stored using a LinkedList data structure.

## Usage

To use this project, follow these steps:

1. Clone the repository.
2. Ensure that the required dependencies for image processing are installed.
3. Place the dermoscopy images in the "Segmented Outputs" folder for Task 1 and the original colored images for Task 2.
4. Run the corresponding scripts for each task, providing the necessary input.
5. The results will be generated and saved accordingly.
6. For Task 3, compare the detected lesion images with the ground truth images and calculate the DICE coefficient.
7. For Task 4, implement the RLC algorithm on the segmented output images and store the encoded RLC images using a LinkedList.

Note: Ensure that the input images and folders are organized as described above to run the scripts correctly.

## Results

The results of each task will be displayed seperatel in the terminal.

Please refer to the specific task's folder or file for the corresponding results.

## License

This project is licensed under the [MIT License](LICENSE).

Feel free to contribute, modify, or distribute this codebase following the terms of the license.

## Acknowledgments

- This project utilizes various image processing techniques and algorithms.
- Credits to the contributors and developers of the used libraries and dependencies.

If you have any questions or need further assistance, please contact [your name or email].
