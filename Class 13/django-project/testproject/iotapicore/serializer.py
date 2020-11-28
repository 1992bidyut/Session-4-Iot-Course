from rest_framework import serializers
from .models import SwitchBox

class SwitchBoxSerializer(serializers.ModelSerializer):
    class Meta:
        model=SwitchBox
        fields='__all__'