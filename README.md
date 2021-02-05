# Hierarchical Navigable Small World for AKNN 
Naive implementation of HNSW for AKNN based on [paper](https://arxiv.org/pdf/1603.09320.pdf)

* Naive implementation without any optimization and used a lot of STL.
* Only implemented the simple SELECT-NEUGHBORS-SIMPLE method for neighborhood selection.

## Simple Random Vector Test Result
* Dimension = 4
* M: number of added neighbors = 10
* MMax: Max number of neighbors in layers >= 1 = 30
* MMax0: Max number of neighbors in layers 0 = 30
* efConstruction: Search numbers in construction 10
* ml: Max number of layers = 2
* Test vector sample each component i.i.d from Unif[0, 1]
* Query sample each component i.i.d from Unif[0, 1] with 100 queries
* Run AKNN with K = 5 to compute top-1 recall

| Num Items   | Top-1 Recall | Brute Force (ms/q) | HNSW (ms/q) | 
| ----------- | ----------- | ----------- | ----------- |
| 10k         | 100%        | 2.72        | 0.15        |
| 100k        | 100%        | 35.32       | 0.26        |
| 1M          | 100%        | 483.74      | 0.42        |
