from django.urls import  path
from . import views

urlpatterns = [
    path('', views.iotrequetslist,name="iot-request-list"),
    path('switchlist/', views.iotSwitchList,name="switch-list"),
    path('switchdetail/<str:pk>/', views.iotSwitchDetail,name="switch-detail"),
    path('switchcreate/', views.iotSwitchCreate,name="switch-create"),
    path('switchupdate/<str:pk>/', views.iotSwitchUpdate,name="switch-update"),
    path('switchdelete/<str:pk>/', views.iotSwitchDelete,name="switch-delete"),
]