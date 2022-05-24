import discord
import os
import requests
import json

TOKEN = 'OTc4Mzk5OTM5OTA0Mjc4NTY4.GlXCVZ.EVnmlgMpQiPjyuz9Zn9swnxwK6xDdP1uj76DvU'

client = discord.Client()

@client.event
async def on_ready():
  print('We have logged in as {0.user}'.format(client))

@client.event
async def on_message(message):
  if message.author == client.user:
    return

  if message.content.startswith('&oi'):
    await message.channel.send('oi')

client.run(TOKEN)