# point_clound_process
This repository documents my personal learning journey in point cloud processing.

Development Environment:

Windows OS
C++ programs implemented with Qt and PCL (Point Cloud Library) (CMake build system, portable to other platforms with minor modifications)
Python programs using Open3D library

## Table of Contents
Chapter 1: Point Cloud Processing
    Section 1: Common Point Cloud Storage Formats & Conversions
    Section 2: Point Cloud Visualization
    Section 3: Spatial Transformations
        1. Translation
        2. Rotation
        3. Planar Projection
        4. Affine Transformation
        5. Scaling

    Section 4: Preprocessing
        1. Outlier Filtering
          - Invalid Point Removal
          - Statistical Filtering
          - Radius Filtering
        2. Downsampling
          - Uniform Sampling
          - Voxel Grid Sampling
          - Farthest Point Sampling (FPS)
          - Random Sampling
        3. Upsampling
          - Coordinate-based Upsampling
          - Feature-based Upsampling

    Section 5: Registration
    1. Iterative Closest Point (ICP) Algorithm

    Section 6: Segmentation
        1. RANSAC Algorithm
        2. DBSCAN Algorithm
        3. K-Means Clustering

    Section 7: Surface Reconstruction
        1. Alpha Shapes Algorithm
        2. Ball Pivoting Algorithm
        3. Poisson Reconstruction
        4. Voxel Grid Reconstruction

