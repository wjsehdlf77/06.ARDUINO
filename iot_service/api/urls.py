from django.urls import path
from .views import greet, sensor_list

urlpatterns = [
     path('greet/', greet),
     path('sensor/', sensor_list)
]
