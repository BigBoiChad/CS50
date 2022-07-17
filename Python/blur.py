# We can use other people's function
# We import the Image(varible  (Class ) but also have funcitons)
# we also import the fucntion
# Image is a structure that not only has data, but functions that we can access with the . syntax, such as with Image.open.
from PIL import Image, ImageFilter

# we make before the image of "CaoKun"
# use Image.open to open a pic
before = Image.open("CaoKun.jpg")

# use before(now before is a class called Image. and one of the funciton is to use filter)
# the filer funciton take as an input of a output of another function
# ImageFilter.BoxBlur()
# this BoxBlur function take 10 means it will blur the pixel using all the pixel that are within 10 radius
after = before.filter(ImageFilter.BoxBlur(10))

# use the build-in save function to save the out
after.save("CaoKun_Blur.jpg")