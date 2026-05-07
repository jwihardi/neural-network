#!/usr/bin/env python3

from pathlib import Path
from urllib.request import urlretrieve
import gzip
import shutil

urls = [
    "https://storage.googleapis.com/cvdf-datasets/mnist/train-images-idx3-ubyte.gz",
    "https://storage.googleapis.com/cvdf-datasets/mnist/train-labels-idx1-ubyte.gz",
    "https://storage.googleapis.com/cvdf-datasets/mnist/t10k-images-idx3-ubyte.gz",
    "https://storage.googleapis.com/cvdf-datasets/mnist/t10k-labels-idx1-ubyte.gz",
]

out_dir = Path("mnist")
out_dir.mkdir(exist_ok=True)

for url in urls:
    gz_path = out_dir / url.split("/")[-1]
    out_path = gz_path.with_suffix("")

    print(f"Downloading {gz_path.name}")
    urlretrieve(url, gz_path)

    print(f"Extracting {gz_path.name}")
    with gzip.open(gz_path, "rb") as f_in:
        with open(out_path, "wb") as f_out:
            shutil.copyfileobj(f_in, f_out)

    gz_path.unlink()

print("Datasets downloaded")
