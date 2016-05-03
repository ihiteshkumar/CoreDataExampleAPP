//
//  ChoreLog+CoreDataProperties.h
//  CoreDataExampleAPP
//
//  Created by Hitesh Kumar on 03/05/16.
//  Copyright © 2016 Hitesh Kumar. All rights reserved.
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "ChoreLog.h"

NS_ASSUME_NONNULL_BEGIN

@interface ChoreLog (CoreDataProperties)

@property (nullable, nonatomic, retain) NSDate *when;
@property (nullable, nonatomic, retain) Chore *chore_done;
@property (nullable, nonatomic, retain) Person *person_who_did;

@end

NS_ASSUME_NONNULL_END
