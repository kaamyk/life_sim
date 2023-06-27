import tkinter as tk
from tkinter import *

class Creatures:
	def __init__(self):
		self.size = 10
		self.speed = 1
		self.x = 50
		self.y = 50
		self.last_meal = 0

	def move(self):
		self.x += 5

def set_window_size(window, width, height):
	window.geometry(f"{width}x{height}")

def update_canvas():
	print("Dans update_canvas")
	canvas.delete("creature")
	tommy.move()
	canvas.create_rectangle(tommy.x, tommy.y, tommy.x+tommy.size, tommy.y+tommy.size, fill="white", tags="creature")
	window.after(100, update_canvas)

window = tk.Tk()
set_window_size(window, 1920, 1080)
canvas = tk.Canvas(window, bg="black", bd=2, width=10, height=10)
canvas.grid(row=0, column=0)
tommy = Creatures()
update_canvas()
window.mainloop()