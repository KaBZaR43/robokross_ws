from setuptools import find_packages
from setuptools import setup

setup(
    name='gkv2_motor_bridge',
    version='0.0.1',
    packages=find_packages(
        include=('gkv2_motor_bridge', 'gkv2_motor_bridge.*')),
)
