#!/bin/zsh

echo "enter age:"
read age

if [[ $age -gt 18 || $age -lt 30 ]]; then
  echo "eligible"
else 
  echo "not eligible"
fi