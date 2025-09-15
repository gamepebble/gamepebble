# Maintainer's guide of GamePebble

How to Operate the Repo (as maintainer)

### Your daily workflow
- Work in `main` branch (protected: require PRs, CI).  
- Develop features in feature branches:  
```

git checkout -b feat/emulator-scaling
git push origin feat/emulator-scaling

```
- Open PR → CI checks run → merge into `main`.  

### Releases
- Tag versions: `v0.1.0`, `v0.2.0`.  
- Each tag triggers GitHub Actions: build host binaries, web demo, STM32 `.bin` → attach to release.  
- Announce in README + site (GamePebble.com).  

### Contributors
- Fork, branch, PR workflow.  
- You review and merge.  
- Encourage them to add examples/games.  

### Community
- Issues → bug reports / feature requests.  
- Discussions (enable GitHub Discussions) for questions + showcase.  
- Link `gamepebble.com` → host emulator builds + docs.  

