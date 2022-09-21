from setuptools import setup, Extension

setup(name="example",
        version="0.0.1",
        description="Example",
        author="Jeremie Melly & Xoeseko Nyomi",
        author_email="test@example.com",
        packages=["example"],
        ext_modules=[
        Extension("example",
            ["example/example.c",]
            )
        ])
