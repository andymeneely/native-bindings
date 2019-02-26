import os
import os.path
import subprocess as sub
import sys

def get_symlink_names(lib, src_dir='', dst_dir=''):
    """
    Determine the correct source and destination symlink file names based on the platform.
    """
    plat = sys.platform
    out = None
    if plat.startswith('darwin'):
        out = ('lib{}.dylib', '{}.so')
    elif plat.startswith('win32'):
        out = ('{}.dll', '{}.pyd')
    else:
        out = ('lib{}.so', 'lib{}.so')
    src_path = os.path.join(src_dir, out[0].format(lib))
    dst_path = os.path.join(dst_dir, out[1].format(lib))
    return (src_path, dst_path)

def main():
    sub.run(['cargo', 'build', '--release']).check_returncode()
    (src_path, dst_path) = get_symlink_names('hello', src_dir='target/release/')
    if not os.path.exists(dst_path):
        os.symlink(src_path, dst_path)

if __name__ == '__main__':
    main()

