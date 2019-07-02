import pylab
import imageio
import skimage
import numpy as np
filename='/home/wuqi/momenta/autoring_benchmark_json/dms/benchmark_result/ffmpeg/speed_test.avi'
vid=imageio.get_reader(filename, 'ffmpeg')
for num,im in enumerate(vid):
    #print im.mean()
    image = skimage.img_as_float(im).astype(np.float64)
    fig = pylab.figure()
    fig.suptitle('image #{}'.format(num), fontsize=20)
    if(num % 10 == 0)
        pylab.imshow(im)
pylab.show()
