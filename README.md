# PrivLR: Privacy Preserving Logistic Regression

PrivLR is Privacy Preserving Logistic Regression implement with C++, using paillier.

# Build


You can build PrivLR by following command: 

```bash
mkdir build && cd build
cmake ../
make
```

If you want to turn off the test sample, run:

```bash
mkdir build && cd build
cmake ../ -DPrivLR_TEST=OFF
make
```

# Acknowledgments

This repository includes code from the following external repositories:

[Microsoft/SEAL](https://github.com/microsoft/SEAL) for cryptographic tools,

[mpc-msri/EzPC](https://github.com/mpc-msri/EzPC) for Network IO.