//
//  Chore+CoreDataProperties.h
//  CoreDataExampleAPP
//
//  Created by Hitesh Kumar on 03/05/16.
//  Copyright © 2016 Hitesh Kumar. All rights reserved.
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "Chore.h"

NS_ASSUME_NONNULL_BEGIN

@interface Chore (CoreDataProperties)

@property (nullable, nonatomic, retain) NSString *chore_name;
@property (nullable, nonatomic, retain) NSSet<ChoreLog *> *chore_log;

@end

@interface Chore (CoreDataGeneratedAccessors)

- (void)addChore_logObject:(ChoreLog *)value;
- (void)removeChore_logObject:(ChoreLog *)value;
- (void)addChore_log:(NSSet<ChoreLog *> *)values;
- (void)removeChore_log:(NSSet<ChoreLog *> *)values;

@end

NS_ASSUME_NONNULL_END
