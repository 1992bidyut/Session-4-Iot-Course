from django.db import models

# Create your models here.

class SwitchBox(models.Model):
    user_id = models.IntegerField(max_length=100)
    switch_id = models.CharField(max_length=100)
    state= models.IntegerField(max_length=10)
    switch_type=models.IntegerField(max_length=10)
