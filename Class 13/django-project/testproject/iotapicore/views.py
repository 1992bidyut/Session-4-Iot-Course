from django.shortcuts import render
from  django.http import  JsonResponse

# Create your views here.

from rest_framework.decorators import api_view
from rest_framework.response import Response
from .serializer import SwitchBoxSerializer
from .models import SwitchBox

@api_view(['GET'])
def iotrequetslist(request):
    res={
        "main-path":"/iotapi",
        "switch-list":"iotapi/switch-list"
    }
    return Response(res)

@api_view(['GET'])
def iotSwitchList(request):
    switchList=SwitchBox.objects.all()
    serializer=SwitchBoxSerializer(switchList,many=True)
    return Response(serializer.data)

@api_view(['GET'])
def iotSwitchDetail(request,pk):
    switchList=SwitchBox.objects.get(id=pk)
    serializer=SwitchBoxSerializer(switchList,many=False)
    return Response(serializer.data)

@api_view(['POST'])
def iotSwitchCreate(request):
    serializer=SwitchBoxSerializer(data=request.data)
    if serializer.is_valid():
        serializer.save()
    return Response(serializer.data)

@api_view(['POST'])
def iotSwitchUpdate(request,pk):
    switch=SwitchBox.objects.get(id=pk)
    serializer = SwitchBoxSerializer(instance=switch,data=request.data)
    if serializer.is_valid():
        serializer.save()
    return Response(serializer.data)

@api_view(['DELETE'])
def iotSwitchDelete(request,pk):
    switch=SwitchBox.objects.get(id=pk)
    switch.delete()
    return Response("Item deleted")